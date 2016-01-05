inherit ROOM;

void create()
{
	set("short", "������");

	set("long", @LONG
�Ĵ����ǻ��������ֱ���ǻ��ĺ������¾����ģ��쳣���������ϸɸɾ���
�ģ�һ����Ⱦ�������ǰ��˸ߵ�����ʣ��ڰٻ���ӳ�У�һ��С�Źصý����ġ�
LONG);

	set("type","house");
	set("exits",([
		"northdown":__DIR__"cloudedge",
	]) );
        set("objects", ([
                __DIR__"obj/huacong" : 1,
       ]) );
	set("coor/x",40);
	set("coor/y",-80);
	set("coor/z",40);
       set("outdoors", "wolfmount");
        set("item_desc", ([
                "С��": "һ�����Ž������š�\n",
                "door": "һ�����Ž������š�\n",
        ]) );

	setup();
}

void init()
{
	object me;
	me = this_player();
	if( me->query("marks/wolf_pass_oldman") )
	{
		add_action("do_knock","knock");
	}
}

int closepath()
{
        if( !query("exits/enter") ) 
        	return 1;
        message("vision","С����������Ϣ�ĺ����ˡ�\n",this_object());
		delete("exits/enter");
	return 1;
}

int do_knock()
{
	add("num",1);
	if(!((int) query("num") % 3))
	{
		if( !query("exits/enter"))
		{
			set("exits/enter",__DIR__"grasscabin");
			message("vision","��֨����һ����С���Զ�����򿪡�\n",this_object());
			call_out("closepath",5);
			return 1;
		}
	}
	else
	{
		message_vision("$N���������С�š�\n",this_player());
		return 1;
	}
	return 0;
}

void reset()
{
	::reset();
	delete("num");
}
