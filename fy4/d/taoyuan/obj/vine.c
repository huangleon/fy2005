inherit ITEM;

void create()
{
        set_name("��֦", ({ "vine" , "��֦"}) );
        set_weight(10000);
        set_max_encumbrance(8000);
        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("prep", "on");
                set("unit", "��");
                set("long", @LONG
һ���ִֵ���֦����û����ȫ����������ģģ�����ؿ��ż���С�֣�
		�䵱���ء�����������
LONG
		);
                set("value", 1);
        }
    ::init_item();
}

int is_container() { return 1; }

