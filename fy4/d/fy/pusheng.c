inherit ROOM;
void create()
{
    set("short", "������");
    set("long", @LONG
�����ñ���һ���θ�ɮ·�����ƳǶ���ʱ���裬��ɮͯ��δ�����ид˵ط���
���飬һ���������ꡣ����һ���ӡ���ɮ����ʶ�飬�˵���������֮������������
�Ѿ�ѧɮ��ҽ������������һ�飺 [31m
        		    ���ֻش�
[32m
LONG
    );

    set("exits", ([
	"east"    	: __DIR__"swind5",
	"north"		: __DIR__"yangsheng",
      ]) );
    set("objects", ([
	__DIR__"npc/hosowner" : 1,
		"/d/loulan/npc/yao" : 1,

      ]) );
    set("coor/x",-20);
    set("coor/y",-240);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);

}
