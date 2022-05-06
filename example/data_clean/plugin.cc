#include "plugin.h"
#include <string>
#include <regex>
using std::regex;
using std::string;

string replaceAll(string str, const string &old_value, const string &new_value);

// Boilderplate code to register the extension implementation.
static RegisterContextFactory register_Example(CONTEXT_FACTORY(PluginContext),
                                               ROOT_FACTORY(PluginRootContext));

bool PluginRootContext::onConfigure(size_t) { return true; }


FilterDataStatus PluginContext::onResponseBody(size_t body_buffer_length,
                                               bool /* end_of_stream */) {
    auto body = getBufferBytes(WasmBufferType::HttpResponseBody, 0, body_buffer_length);
    std::string requestBody = string(body->view());
    std::regex regexp(".*(\\d{3})(\\d{4})(\\d{4}).*");
    std::regex regexp1(".*([^0-9]{1})(13|14|15|17|18|19)(\\d{9})([^0-9]{1}).*");
    std::smatch base_match;
    while (std::regex_match(requestBody, base_match, regexp1)) {
        LOG_WARN("regex_match phone ...");
        string basic =  base_match[2].str() + base_match[3].str();
        string replace_basic = std::regex_replace(basic, regexp, "$1****$3");
        requestBody = replaceAll(requestBody, basic, replace_basic);
        setBuffer(WasmBufferType::HttpResponseBody, 0, body_buffer_length, requestBody);
    }
    return FilterDataStatus::Continue;
}

string replaceAll(string str, const string &old_value, const string &new_value) {
    while (true) {
        string::size_type pos(0);
        if ((pos = str.find(old_value)) != string::npos)
            str.replace(pos, old_value.length(), new_value);
        else break;
    }
    return str;
}
