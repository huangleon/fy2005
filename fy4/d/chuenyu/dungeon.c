// Room: /d/chuenyu/dungeon.c

inherit ROOM;

void create()
{
        set("short", "�̷�");
        set("long", @LONG
�㴦��һ����ʪ�ĵ�������εĽ��������һЩ�ɲݣ��ɲ���մ���˰���ɫ
��Ѫ����������ñ��������������ǽ�ϡ�ż��֮�䣬�㻹������������֨֨��
�ļ������
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  		"northwest" : __DIR__"tunnel3",
  		"north"   : __DIR__"tunnel4",
	]));

	set("objects", ([
                __DIR__"npc/chuenyu" : 1,
		__DIR__"npc/xiaojuan2" : 1,
	]) );

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
