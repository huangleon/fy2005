inherit ROOM;
void create()
{
        set("short", "��լ");
        set("long", @LONG
��լ��һ��ֻ�����ȴ����Ĳ�¥�ߵ�լ�ӡ�����¥�ȵ�һ���͹����棬��
����¥���Ĳ�¥���ȶ���¥͹���������ķ��ݵ���Ź��ϵĻ��ƣ��������������
�����ӣ����Ǽ������ݶ����Ͷ�¥���������Ƶ�ͻ�����֣���һ��ʹ����լ�ӿ�
������һֻ�����ŵĴ���
LONG
        );
        set("exits", ([ 
		"east":  __DIR__"mroad2",
		"up":  __DIR__"house1a",
	]));
	set("objects", ([
        	__DIR__"npc/tan1" : 1,
        ]) );

        set("item_desc", ([
	
	 ]));
	set("coor/x",-20);
	set("coor/y",-10);
	set("coor/z",0);
	set("map","taiping");
	setup();
}



int valid_leave(object me,string dir) {
        object ob,end_room,*inv;
	int i;
	
	if( userp(me) && dir == "up" && ob=present("tan tianlong",this_object())) {
		return notify_fail(ob->name()+"����һ���ۣ���ס�����ȥ·��\n");		
	}
	return 1;
}