
inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
��ľԽ��Խ�࣬��ľ��û���������ȴҲ����������ת����ͷ���ֲ��嶫����
���ˣ������ܿ�ֻ������ǰ��ɫ����һ�����Ѳ�������ʱ��·��ԭ���ö���������
����Ҳ����е����겻����
LONG
        );
    set("exits", ([ 
  		"south" : __DIR__"xiaodao",
	    "north" : __DIR__"milin",
	    "west" : __DIR__"milin2",
	    "east" : __DIR__"milin",
	]));
   
    set("outdoors", "huashan");

	set("coor/x",-8);
	set("coor/y",-45);
	set("coor/z",27);
	setup();

}

int valid_leave(object me, string dir){
	if(dir != "south") {
		tell_object(me, "���ܵľ�ɫ������˵��������һ����");
		message_vision("$N����ģ���ֻ��ͷ��Ӭһ����������ת��תȥ��\n", me);
	}
	return 1;
}
