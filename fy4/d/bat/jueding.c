inherit ROOM;
void create()
{
        set("short", "�·����");
        set("long", @LONG
���羢�������¾����۵ף�������˼�ľ�����ֻ�о�����ƥ�ĸ��ֲ��ܵ���
������Ǹߴ���ʤ����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "southdown" : __DIR__"renjiandao3",
]));
        set("outdoors", "bat");
        set("objects", ([
        __DIR__"npc/baiyiren": 1,
                        ]) );

	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",70);
	setup();
}
