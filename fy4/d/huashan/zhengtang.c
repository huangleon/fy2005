
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���ڹ��߳��㣬���Դ��ſ�ǽ����һ����̴ľ��������̯����һ����û�����
���ֻ����پ��ı�����ʾ�����������Ĺ��������������Ǽ�����̴ľ�Σ�ǽ�ϲ�
������ع���һЩ�����ֻ���
LONG
        );
    set("exits", ([ 
  		"west" : __DIR__"bieyuan",
	]));
 
 	set("objects", ([
 		__DIR__"npc/kumeimaster" : 1,
 	]));  
    set("indoors", "huashan");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
    replace_program(ROOM);
}

