// СС������
//QC by TIE

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "é����");
        set("long", @LONG
���ﵱ��һ�����ӵ�Ҳ���ǿ�󡣵������������ң������ӳʣ������齣���壬
��������輿꣬ʲô���У����ҵĶ���һ�ݡ����������е��ã�������ȫ���У�ֻ
�Ƿǵ������΢�����Ҽ�ֱ������Ц�Էǡ�����ݽ�ľ�ܣ����ż�����ᣬ������
ȴд�š��ؾ������֣�����Զ��ż����������������޺��á�����һ����������
�����㰸��д���ǡ����۱�����֣��ұ��ݽ�СС��¯�ϣ�����ֻ�������ڵĹ�
�ӣ��������������磬��Ȼ������������ˡ�����һ��С�ţ��ص�����ʵʵ��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
    "east" : __DIR__"outroom",
]));

        set("item_desc", ([
                "door": "һ��ľ�Ƶ�С�ţ��ص��������ܣ������֪�����浽����ʲô\n",
		        ]) );
        set("objects",([
                       AREA_TIEFLAG"npc/drinkmonk" : 1,
                       AREA_TIEFLAG"obj/kaolu" : 1,
                      ])  );
           
 
	set("coor/x",90);
	set("coor/y",-90);
	set("coor/z",0);
	setup();

}

void init()
{
   add_action("do_open","open");
}


int do_open(string arg)
{
    object ob;
    if (arg!="door") return notify_fail("��Ҫ��ʲô��\n");
    if(query("exits/south")) return notify_fail("���Ѿ��ǿ����ˡ�");
    if( arg == "door" && ob=present("drink monk", this_object()))
    {
    	message_vision(HIB "�Ǻ��г�������������СС�����£����������ߵã���ֻ�������Ż�ȴ�����������ã�\n"NOR,this_player());
       	return 1;
	 }
     message_vision("$N��С�Ŵ򿪡�\n",this_player());
     set("exits/south",__DIR__"maoroom1");
     call_out("closedoor",4);
     return 1;
}


int closedoor()
{  
    if( !query("exits/south") ) return 1;
    message("vision","С���Լ������ˡ�\n", this_object());
    delete("exits/south");
	return 1;                
}

void reset(){
	object obj;
	::reset();
	if(!present("kaolu", this_object())) {
		obj = new(AREA_TIEFLAG"obj/kaolu");
		obj->move(this_object());
	}
}