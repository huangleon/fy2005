inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
�����ñ���һ���θ�ɮ·�����ƳǶ���ʱ���裬��ɮͯ��δ�����ид˵ط�����
�飬һ���������ꡣ����һ���ӡ���ɮ����ʶ�飬�˵���������֮�������������ѽ�
ɮ��ҽ����ѧ����������һ�飺 [32m
        		    ���ֻش�
[37m
LONG
	);
	
	set("exits", ([
		"east"    	: __DIR__"swind5",
		"north"		: __DIR__"yangsheng",
	]) );
	set("objects", ([
		__DIR__"npc/hosowner" : 1,

			]) );
	set("coor/x",-10);
	set("coor/y",-50);
        set("coor/z",-300);
	setup();
       replace_program(ROOM);

}
