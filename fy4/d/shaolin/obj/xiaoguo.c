inherit ITEM;

void create()
{
        set_name("С��", ({ "small wok", "wok" }) );
        set_weight(500);
        set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��ר��Ϊ���ɺʹ�����ղ˵�С��\n");
                set("value", 1);
        }
}

int is_container() { return 1; }

