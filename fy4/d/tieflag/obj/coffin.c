
inherit ITEM;

void create()
{
        set_name("ʯ��", ({ "coffin"}) );
        set_weight(50000); 
		set_max_encumbrance(8000);
        set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("prep", "on");
                set("unit", "��");
                set("long", "һ���޴��ʯ�ס�\n");
                set("value", 1);
        }
    	::init_item();
}
int is_container() { return 1; }

void init()
{
        add_action("do_open","open");
}

int do_open(string arg)
{
        object sp;
		if(!arg="coffin"||!arg="ʯ��") return 0;
        message_vision("$N�����ƶ�ʯ�׵ĸ���...\n",this_player());
        if(query_temp("been_get"))
                return notify_fail("���ƿ�ʯ�ף�������տ���Ҳ��ʲôҲû�С�\n");
        set_temp("been_get",1);
    	tell_object(this_player(),"�㷢���������һ����ǹ����������˳�����\n");
    	sp=new(__DIR__"spear");
    	sp->move(this_player());
    	return 1;
}
