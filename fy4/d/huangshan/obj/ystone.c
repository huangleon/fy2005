inherit ITEM;

void create()
{
        set_name("��ʯ", ({ "suishi", "��ʯ", "stone", "sui shi" }) );
        set_weight(1500);
        set_max_encumbrance(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "
����һ����ʯͷ����ֵ��ǣ������������������ˮ������������������
��˿������������Ҹ���������ĵط���Ҳ���ܰ������ѿ������浽��
��ʲô���������\n");
                set("value", 1);
                set("no_drop",1);
                
        }
	::init_item();
}


void init() {
	if (this_player() == environment() ) {
		add_action("do_burn", "burn");
	}
}


int do_burn(string arg) {
	
	if( arg != "suishi" ) return notify_fail("��Ҫ��ʲô��\n");
	if (!environment(this_player())->burn_notify(this_object(), 0))
		return notify_fail("��Ҫ�Ҹ����Ժ濾�ĵط����С�\n");	// hmm, not a good coding
	return 1;
}

