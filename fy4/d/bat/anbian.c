// Apstone, Inc.
inherit ROOM;
void create()
{
 set("short", "�˼����");
 set("long", @LONG
ʯͷ������ɫ�ģ��䡢Ӳ��������ŭ���Ĵ��ź���������ǧ����Х�������ڡ�
�������ܽ�ʯ���У�����ÿһ�������д����Ĵ�ֻ������������һֻֻ�����޾�
��ҧס��С�á����۶����ɣ����̵Ĵ����������ܲ��Ϻ����������ɱ��
LONG
	);

    set("exits", ([ /* sizeof() == 4 */
        "east" : __DIR__"dong",
        "west" : __DIR__"kongdi",
    ]));
	set("objects", ([
        __DIR__"npc/dizi"   : 2,
        __DIR__"npc/xunluo" : 1,

    ]));

	set("outdoors", "bat");
	set("coor/x",-10);
	set("coor/y",-30);
	set("coor/z",30);
	setup();
	replace_program(ROOM);
}



