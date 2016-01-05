inherit ROOM;

void create()
{
	set("short", "����");

	set("long", @LONG
��ɽ���������Ȼխ��ֻ�����У������浹��ʮ�ֿ����а˾�������м�
͸��һ����⣬�����촰һ�㣬���������������ⶴ����أ��Ĵ��ѻ��Ų���Ұ
�ǵĲ���ʳ�����׹ǣ������ȳ���
LONG);

	set("item_desc", ([
		"ɽ��": "���ɽ��ȫ�޳�·��ֻ��һ�������ƺ���������ȥ��������죩��\n",
        "cave" : "���ɽ��ȫ�޳�·��ֻ��һ�������ƺ���������ȥ��������죩��\n",
//        "����": "������ڸ�����ɽ���ϣ�����ֻ������ȥ���ãң��ף̣���\n",
 	
    ]) );
	set("exits", ([
	])); 
	set("objects",([
          __DIR__"npc/sanlang":1,
          __DIR__"npc/yaomei":1,
            __DIR__"npc/xiaowan":1,
   	]) );
    set("indoors", "wolfmount");
	set("coor/x",-30);
	set("coor/y",20);
	set("coor/z",-10);
	setup();
}

void init()
{
	add_action("do_crawl", "crawl");
}

int do_crawl(string arg){
    object 	me;

	if(!arg) {
		write("��Ҫ�������\n");
		return 1;
	}
    if( arg == "down" || arg == "ɽ��"|| arg == "out"|| arg== "cave" ){
		me = this_player();
		message_vision("$Nץ��ɽ���ϵ��Ӳݣ�����������ȥ��\n", me);
		me->start_busy(2);
        	call_out("fliping",2,me);
        	me->stop_busy();
        	return 1;
    } else {
        me = this_player();
        tell_object(me, "�㲻������"+arg+"��\n");
        return 1;
    }
}

int fliping(object me)
{
	object room;
	if( !me->is_ghost()) 
	{
		message_vision("$N��������ɽ����\n", me);
		room = find_object(__DIR__"wolfslope");
		if(!objectp(room)) room= load_object(__DIR__"wolfslope");
		me->move(room);       
	}
        return 1;
}
