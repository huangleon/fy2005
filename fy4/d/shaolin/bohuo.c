// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
	object con, ob;
        set("short", "�����");
        set("long", @LONG
���������ղ˵ĵط���������ɮ�����ڴ�����ղˣ���������С�����ɣ���
��Ĳ����ո����ɺʹ���гԵģ���ΪѰ��ɮ�ˣ���Ʒ���Ļ�ֻ�л�¸һ�£���˵
��Щ���ж�������ҩ�ģ�������������档���ܴٽ���ѧ��Ϊ��
LONG
        );
        set("exits", ([ 
 "south" : __DIR__"qianzao",  
]));
        set("objects", ([
                __DIR__"npc/monk5_sentry" : 2,
       ]) );

	set("coor/x",-20);
	set("coor/y",50);
	set("coor/z",10);
	setup();
	con = new(__DIR__"obj/xiaoguo");
	ob  = new("obj/medicine/pill_bupin");
	if(ob && con) {ob->move(con); con->move(this_object());}
        con = new(__DIR__"obj/xiaoguo");
        ob  = new("obj/medicine/pill_bupin");
        if(ob && con) {ob->move(con); con->move(this_object());}
        con = new(__DIR__"obj/xiaoguo");
        ob  = new("obj/medicine/pill_bupin");
        if(ob && con) {ob->move(con); con->move(this_object());}

}
