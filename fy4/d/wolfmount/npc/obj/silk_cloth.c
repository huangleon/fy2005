#include <armor.h>
inherit CLOTH;

void create()
{
    set_name("������", ({"silk cloth", "cloth"}));
    set_weight(1000);
    if( clonep() )
        set_default_object(__FILE__);
    else 
    {
        set("long","һ����ɫ��˿�ۣ��ʵؾ������ü���ϸ�����������з��ˡ�\n");
        set("material", "cloth");
        set("unit", "��");
        set("value", 4);
        set("armor_prop/armor", 5);
    }
    ::init_cloth();
}
