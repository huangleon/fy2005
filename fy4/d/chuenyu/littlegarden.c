
inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long", @LONG
�������Ϻ���С��԰����԰���кܶ������Ļ��䡣���Ϻ����ǿ�������ά����
�Ƶġ��������ǻ����Ĵ�ü��ڣ��кܶ����������һ�߼�����һ��˵Ц��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"home",
]));
        set("objects", ([
                __DIR__"npc/flowergirl" : 5,
        ]) );
        set("outdoors", "chuenyu");
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",-20);
	setup();
}

