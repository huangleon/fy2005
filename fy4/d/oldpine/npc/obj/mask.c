// mask.c

inherit EQUIP;

void create()
{
        set_name("����ͷ��", ({ "mask" }) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 3);
                set("material", "cloth");
                set("armor_type", "mask");
                set("armor_prop/id", ({"maskman"}) );
                set("armor_prop/name", ({"������"}) );
                set("armor_prop/short", ({"������(maskman)"}) );
                set("armor_prop/long", ({
                        "�����ͷ�ϴ�������ͷ�֣��˳�׼����ʲ�ỵ�¡�\n"
                }) );
        }
}
