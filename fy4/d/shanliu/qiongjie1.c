// Room: qiongjie1.c --- by MapMaker

inherit ROOM;

void create()
{
	set("short", "���");

	set("long", @LONG
�����������̸����ֶ�����Ҫüͷ���壬��Ϊ�����ֱ����ؤ�����ã�����
�Ĵ����ǳ���������󣬵���ֵ���ȴ������Щ�������ӳ��������Ȼ����Ǵ�
��������������ɥ�����ߣ���Ϊ��Զ�������ڽ�����С��������"����Ӷķ�"��
LONG);
	//{{ --- by MapMaker
	set("exits",([
		"northwest":__DIR__"qiongjie2",
    		"east": AREA_MANGLIN"southsearoad1",
	]) );
	//}}
	set("objects", ([
		"/obj/npc/beggar" :1,
		"/obj/npc/scavenger"  :1,
	]) );
        set("outdoors", "shanliu");
	set("coor/x",65);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
