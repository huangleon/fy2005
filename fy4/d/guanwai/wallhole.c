inherit ROOM;

void create()
{
        set("short", "���ʯ��");
        set("long", @LONG
�����ڴ������ұ��ϵ�ʯ�ߡ�������һ��ɫ�����޵�ȴ�ֲ�֮���ıڻ�������
��һ�������������ɲ��Ů������˱��һ�����˵����衣����ϸ�µĻ��濴������
������
LONG
        );
        
        set("exits", ([ 
		"east" : __DIR__"woodhouse",
		"south" : __DIR__"templeyard",
	]));
	set("objects", ([
                __DIR__"npc/qi" : 1,
        ]) );       

	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

void init()
{
	add_action("do_sware", "swear");
}

int do_sware()
{
        object me,obj;
        me = this_player();
        obj = present("qi xiaoyan", this_object());
        
        message_vision("$N֣�صض���ǽ�ϵ���ɲ���¶��ģ�����й�ܣ�����ͬǽ��������һ��\n����ɲ��Ů�������裮����\n", me);
        if( me->query_temp("marks/guanwai_knowsecret") )
        	call_out("open_path",2,me,obj);
        return 1;

}

void open_path(object me, object obj)
{
    if (!obj || !me || environment(obj)!= environment(me))	return;
    	
    message_vision("$N����ص��˵�ͷ��������ǽ��һ��ʯש��һ��һ�졣ʯ�ڻ���\n�ƿ���¶���˼��ܿߡ�\n", obj);
 	if( !query("exits/west") ) 
 	{
		set("exits/west", __DIR__"secretroom");
		call_out("close_path", 5);
	}
}

void close_path()
{
        if( !query("exits/west") ) 
        	return;
        message("vision","ʯ���������죬�ֵ�ס��ȥ·��\n",this_object() );
	delete("exits/west");
}