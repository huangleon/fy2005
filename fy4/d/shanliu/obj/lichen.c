inherit ITEM;

void create()
{
        set_name("��̦", ({ "lichen" }) );
        set_weight(100);

        set("no_get", 1);
        set("no_shown", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�����ͱ���ÿ�����߱�����һ����̦����ʮ�Ա�ֱ���ϡ�\n");
                set("value", 1);
        }
}

void init()
{
	add_action("do_dig","dig");
	add_action("do_climb","climb");
}

int do_dig(string arg)
{
	object me;
	
	me=this_player();
	if(!arg) return 0;
	if(arg!="lichen"&&arg!="��̦")
		return 0;
	if(query("digged"))
		return 0;
	message_vision("$N����̦����ȥ��ץ��һ�Ѻ��࣬��Ȼ�Ǹ�СС��Ѩ��\n",me);
	set("digged",1);
	return 1;
}

int do_climb(string arg)
{
	object me;
	
	me=this_player();
	if(!arg) return 0;
	if(arg!="up")
		return 0;
	message_vision("$NС������Ĳ�����̦��ȥ��Ķ�Ѩ����������ȥ��\n",me);
	me->move("/d/shanliu/sheshenya");
	return 1;
}
	
	

