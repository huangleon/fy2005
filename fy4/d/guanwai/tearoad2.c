
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
  		"west" : __DIR__"tearoad1",
  		"southeast" : __DIR__"nujiang",
	]));
        set("outdoors", "guanwai");

	set("coor/x",130);
	set("coor/y",-140);
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
	if ( arg == "west" || arg == "southeast") {
	        if(random(5)){
	                this_player()->move(this_object());
	                return 1;
	        } 
        } else 
        	return 0;  
        return 0;
}

