inherit ROOM;
void create()
{
        set("short", "��լԺ");
        set("long", @LONG
����һ��ֻ�����ȴ����Ĳ�¥�ߵ�լ�ӣ�������Ψһ���������ķ���֮һ��
ԭ��ס�ŵ�һ���Ѹ����ϻ�����ң���լԺ�ĳ��˳�Ц����ʱ��ۡ������¥�ȵ�һ
���͹����棬������¥���Ĳ�¥���ȶ���¥͹���������ķ��ݵ���Ź��ϵĻ��ƣ�
����������������ӣ��Ǽ������ݶ����Ͷ�¥���������Ƶ�ͻ�����֣�ʹ����լ
�ӿ�������һֻ�����ŵĴ���
LONG
        );
        set("exits", ([ 
		"west":  __DIR__"mroad5",
		"up":	__DIR__"house3a",
		"east":	__DIR__"house3b",
	]));
	set("objects", ([
        	__DIR__"npc/zhangtie" : 1,
        ]) );

        set("item_desc", ([
	
	 ]));
	set("coor/x",-10);
	set("coor/y",-50);
	set("coor/z",0);
	set("map","taiping");
	setup();
}


int valid_leave(object me, string dir){
	object zhang;
	
	if (dir=="up" && zhang=present("zhang tie",this_object()) 
		&& me->query("family/master_id")!="master yin") {
		message_vision("����˵�������ɴ��ų�������Ϣ��������\n",me);
		return notify_fail("");
	}
	return 1;
}

