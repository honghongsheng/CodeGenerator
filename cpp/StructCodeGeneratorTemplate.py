# -*- coding: utf-8 -*-
_author_ = 'Administrator'
#######################################################
#                       头文件
#######################################################
#头文件
TEMPLATE_DEF = u'''\
{{FILE_COMMENTS}}
#ifndef {{FileName}}_{{tag}}_H_
#define {{FileName}}_{{tag}}_H_
{{IncludeCodes}}
namespace {{Namespace}}
{
{{Contents}}
}//{{Namespace}}
#endif //{{FileName}}_{{tag}}_H_
'''

#struct/class
TEMPLATE_STRUCT_DEF = u'''\
/**
 * @{{TypeNameWithInherit}}
 */
struct {{ExportMacro}} {{TypeNameWithInherit}} {
    {{Variables}}

    {{TypeName}}();
    {{TypeName}}(const {{TypeName}}& right);
    {{TypeName}}& operator=(const {{TypeName}}& right);
    {{Serialise}}
};
'''

#struct/class 序列化json
TEMPLATE_STRUCT_FUNC_JSON_DEF = u'''\

void fromJson(Json::Value& jsonObj);
void toJson(Json::Value& jsonObj) const;
'''

#struct/class 序列化xml
TEMPLATE_STRUCT_FUNC_XML_DEF = u'''\

void fromXml(Xml& xmlObj){}
void toXml(Xml& xmlObj) const{}
'''

#######################################################
#                       源文件
#######################################################
#源文件
TEMPLATE_IMPL = u'''\
{{FILE_COMMENTS}}
{{IncludeCodes}}
namespace {{Namespace}}
{
{{Contents}}
}//{{Namespace}}
'''

TEMPLATE_STRUCT_IMPL = u'''\
//////////////////////////////
///{{TypeName}}
////////////////////////////////
{{TypeName}}::{{TypeName}}()
    {{InitCode}}
{}

{{TypeName}}::{{TypeName}}(const {{TypeName}}& right)
    {{AssignCode}}
{}

{{TypeName}}& {{TypeName}}::operator=(const {{TypeName}}& right)
{
    assign(&right);
    return *this;
}
{{Serialise}}
'''

TEMPLATE_STRUCT_FUNC_JSON_IMPL = u'''\

void {{TypeName}}::fromJson(Json::Value &jsonObj) {
    {{FromJsonObj}}
}

void {{TypeName}}::toJson(Json::Value &jsonObj) const {
    {{Format2JsonObj}}
}
'''