// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����¥��¥");
        set("long", @LONG
������ɽ�紵�������˾���һ��¥��ʯ������֦Ҷ���ٳ��ȣ�̽�ֿɴ���վ
�ڴ˴������춼����ɽ��ֱ��ɽ�ţ�������ֱ������������ǡ�ơ�ͻأ����񷡱��
ʢ��������������ش������������ģ�����ɽ�澰��ɡ�
LONG
        );
    set("exits", ([ 
  		"down" : __DIR__"yuping2",
	]));

    set("indoors", "huangshan");
	set("coor/x",-70);
	set("coor/y",-10);
	set("coor/z",60);
            set("objects", ([
	__DIR__"npc/taihuwang" : 1,
                        ]) );
    
    
	setup();
        replace_program(ROOM);
}
