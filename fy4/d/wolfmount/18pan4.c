inherit ROOM;

void create()
{
	set("short", "ʮ����");
	set("long", @LONG
ɽ·����������У������ɼ���᾵Ĺ�ʯ���ң��������������ٻ��ƣ���ãã
��ɽ���п�ȥ����������ɭ�ɲ�������˱����µĵ��ƣ������ɽ��ʯ�䣬���ﴩ
�С�Ũ���в�ʱð��һ��˫������â�Ĺ��ۺݺݵض����������
LONG);

	set("type","road");
	set("exits",([
		"northdown":__DIR__"bigstage",
        "southup":__DIR__"18pan2",
	]) );
       set("outdoors", "wolfmount");
	set("coor/x",-20);
	set("coor/y",65);
	set("coor/z",-45);
        set("objects", ([
        __DIR__"obj/stone1":1,
		__DIR__"npc/fwolf2":1,
		__DIR__"npc/fwolf2a":1,
                        ]) );
	setup();
	replace_program(ROOM);
}
