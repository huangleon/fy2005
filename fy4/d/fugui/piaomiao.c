inherit ROOM;

void create()
{
	set("short", "��������");

	set("long", @LONG
���Ǽ������������ʧ�ޣ����ưܲ�����ɽ�Ÿ��࣬������ƣ����б����
�����ɼ������ҳ�����ʵ�������ԭ�ȵ�Ҳ�����������ԴӲ�Զ������Կ�ʼ�ֹ�
��һ����ն�û���Ӹ������ˡ�
LONG);
	set("outdoors", "fugui");
	set("type","street");
	set("exits",([
		"southeast":__DIR__"shanlu6",
	]) );

	set("objects", ([
        	__DIR__"npc/guo" : 1,
//            "/obj/specials/ding/ding_fg" : 1,
        ]) );
	set("coor/x",-50);
	set("coor/y",140);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
