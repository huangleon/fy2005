// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "��¥");
        set("long", @LONG
�Ѿ���ϰ�����������Ĺ����¿�������������ש��΢��͹��ƽ����˵����ɨ
��ɮ�����µģ���������Ҳ���������еĺ����ڣ�����ǽ��֮�ϻ����˱ڻ���ֻ��
��ã����Կ����ˡ�
LONG
        );
        set("exits", ([ 
  		"up" : __DIR__"zhonglou3",
  		"down" : __DIR__"zhonglou",
	]));
	        set("objects", ([
                __DIR__"npc/monk51_sentry" : 1,   
       ]) );
	set("coor/x",20);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
