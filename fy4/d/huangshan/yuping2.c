// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����¥һ¥");
        set("long", @LONG
¥����ÿһ��Լ����������䣬�����ǳ��ȡ������ڻ���ɾ�����û������
����������Ȼ���ıڿտգ�ֻʣ�µ񻨵Ĵ������ٳ�������һ��ʯ������ï�ܵ�֦
���Ѿ���չ��¥�ϡ���¥��˵��һ���Ծ��Ǹ���������Ϊ��Ѱ���ڻ�ɽ���ӵ���ҽ
Ϊ������β���������û����֪����
LONG
        );
    set("exits", ([ 
  		"down" : __DIR__"yuping",
		"up" : __DIR__"yuping3",
	]));

    set("indoors", "huangshan");
	set("coor/x",-70);
	set("coor/y",-10);
	set("coor/z",50);
                set("objects", ([
	__DIR__"npc/xiaosi" : 2,
                        ]) );
    
	setup();
        replace_program(ROOM);
}
