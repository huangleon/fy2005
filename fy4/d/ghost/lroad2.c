
inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
����������һ������������·��·���Ӳݴ�����û��ס�ң�·����Ţ��������
�����С�����ǰ�߾ͽ�����һƬԭʼɭ�֣���ѹѹ���ޱ��޼ʣ�˵����û�����߳�
����������˰�����������ľ���ɰ͡�����˼���������ֳ�û�ĵط���
LONG
	);
	set("exits", ([
                "north" : __DIR__"lroad1",
                "south" : __DIR__"lroad3",
	]));
	set("coor/x",-90);
	set("coor/y",60);
	set("coor/z",10);
	setup();
replace_program(ROOM);

}
