
inherit ROOM;

void create()
{
        set("short", "����֮��");
        set("long", @LONG
һ�����Ϲ��ź�ɫӥ��Ļ����ޱȵ����������ޱ��޼ʵĴ��ԭ���
����ȥ��������ѵ��£������ڲرߣ���ɫ��ӥ�������ı��Ǽ��������ѣ���
�������Ǽ����ǲ�ҩζ���������¸��Ҳ����Щ֪����֪���Ĳ�ҩ������
�����һ���׷���������Ŀ����
LONG
        );
        set("exits", ([ 
        "south" : __DIR__"grassland3",
	]));
        set("objects", ([
               __DIR__"npc/songfuzi" : 1,
        ]) );   
        set("indoors", "guanwai");
	set("coor/x",60);
	set("coor/y",40);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
