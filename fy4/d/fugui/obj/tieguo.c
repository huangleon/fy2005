inherit ITEM;

void create()
{
        set_name("����", ({ "tieguo", "����" }) );
        set_weight(500);
        set_max_encumbrance(40000);        
	set("prep","on");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����\n");
                set("value", 1);
                set("long", "һֻ��������ľͷ���Ӱ���ţ�����м�ֻ��Ѽ��\n");
        }
	::init_item();
}

int is_container() { return 1; }

