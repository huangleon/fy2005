
inherit ROOM;

void create()
{
        set("short", "����ŵ�");
        set("long", @LONG
Զ������ʱ������������������ٳ��������������أ���ͨ���񣬶�����Խ��
�ŵ�������ʱ���������䡶���顷�о�����ᵽ���ɵ�����ެ�ĵ�·�����Ų����
��ʹ�����������·�����������ʵ�Ĳ���ŵ����ŵ���ʯ�����Բ������ж����
�������ӡ�����Ե����ض��Ͽ̻��Ÿ��������ڽ����ԡ������������߰�ʮ���
�������˷�̸������������Ͳ裬�ò���������������Ҷ��صĹ��¡�
LONG
        );
        set("exits", ([ 
  "northwest" : __DIR__"birdroad2",
  "east" : __DIR__"tearoad2",
]));
        set("outdoors", "guanwai");

	set("coor/x",100);
	set("coor/y",-90);
	set("coor/z",0);
	set("objects", ([
                __DIR__"obj/shiban" : 1,
        ]));
	setup();
}

void init()
{
        add_action("do_go","go");

}

int do_go(string arg )
{
	if ( arg == "east" || arg == "northwest") {
	        if(random(5)){
	                this_player()->move(this_object());
	                return 1;
	        } 
        } else 
        	return 0;  
        return 0;
}

