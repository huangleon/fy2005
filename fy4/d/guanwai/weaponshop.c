
inherit ROOM;

void create()
{
        set("short", "����֮��");
        set("long", @LONG
һ�������������񣬶��Ϲ��ź�ɫӥ�𡪡���ɫ��ӥ���ڲر�������
��ս������Ѫ��ʤ���������а����˲����ó��õĸ�ʽ��������ȻԶ������ԭ
�ǰ㾫�»��󣬵��ʵؼ�Ӳ��ʵ���;á������а�Ū�Ÿ�ʽ��ǹ�ľ��Ǹ�����
���ɰ���Ů����
LONG
        );
        set("exits", ([ 
        "north" : __DIR__"grassland3",
	]));
        set("objects", ([
               __DIR__"npc/sunshine" : 1,
        ]) );   
        set("indoors", "guanwai");
	set("coor/x",60);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
