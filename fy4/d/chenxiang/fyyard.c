inherit ROOM;

void create()
{
	set("short", "���ٻ�Է");

	set("long", @LONG
�����Ƿ��ƿ�ջ�����ٻ�Է��ͨ����ú����ԵĿͷ���԰�Ӳ��󣬿�������ɫ
�Ļ�����һ��������Ůվ�����ٻ��£�վ������ɴ��������һ�����ض����ʵ�
����ʹ�������Ե����ٻ�Ҳ����ʧȥ��ɫ��������Ӱ�л��ƺ��и������˾�����վ
�š�
LONG);

	set("type","grassland");
	set("exits",([
		"west":__DIR__"tingfengge",
		"south":__DIR__"fyhall",
	]) );
        set("outdoors", "chenxiang");
	set("coor/x",20);
	set("coor/y",60);
	set("coor/z",0);
	set("objects" , ([
		__DIR__"npc/yuan":1,
		__DIR__"npc/wei":1,
	]));
	setup();
	replace_program(ROOM);
}
