// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ϰ����");
        set("long", @LONG
���ǵ�������ѧϰ�书���ڣ���������似�������ʴ�ӱ�ĺ󱲵����ڴ������
���г���򵥣�Ω���м乩��һ������񣬾ݴ�����Ժ������书��ͻ���ͽ���
�������е������࣬���ݶ��Ǵ���ڤ˼֮�ˡ�
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"damo",
]));
        set("objects", ([
                __DIR__"obj/guanyin" : 1,
       ]) );

	set("coor/x",10);
	set("coor/y",90);
	set("coor/z",20);
	setup();
	replace_program(ROOM);

}
