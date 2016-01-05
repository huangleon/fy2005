// СС������
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "é����");
        set("long", @LONG
С������ССһ��é�ݣ����õþ��Ǿ��»����Ѽ�������������գ�����ױ̨��
���϶��Ŵ�����̨���������������Ի��м���Ů�������õ�ľ�ᡣ�紵���ʣ�¶��
����ǽ�ڣ�ǽ�ھ�����ͭ���ơ��ݽ���һ���ӣ������¡�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
        "down"  : __DIR__"didao",
        "north" : __DIR__"maoroom",
]));

        set("item_desc", ([
                "ľ��": "һ��Ů���õ�ľ�ᣬ���ϻ����ż�����˿��\n",
				"comb" :"һ��Ů���õ�ľ�ᣬ���ϻ����ż�����˿��\n",
                "ױ̨" :"һ����ľױ̨��̨��ѹ�Ÿ�ֽ��������һ��"YEL"С��\n"NOR,
                "desk" :"һ����ľױ̨��̨��ѹ�Ÿ�ֽ��������һ��"YEL"С��\n"NOR,
                "С��" :"���С��������������������죩\n",
                "cabinet" :"���С��������������������죩\n",
                "ֽ��" :@TEXT
����д���ǣ�
    �����������ˣ���Ѱ�Ҳ������������������İɣ���Ϊ���ܵĿ࣬
��������Ը�ģ����ã�
                                                   ��������
                                                      
TEXT,                                                  
                "paper" :@TEXT
����д���ǣ�
    �����������ˣ���Ѱ�Ҳ������������������İɣ���Ϊ���ܵĿ࣬
��������Ը�ģ����ã�
                                                   ��������
                                                      
TEXT                                                  
                                              
        ]) );
//        set("objects",([
//                       __DIR__"npc/drinkmonk2" : 1,
 //                     ])  );
           
 
	set("coor/x",90);
	set("coor/y",-100);
	set("coor/z",0);
	setup();

}

void init()
{
   add_action("do_pull","pull");
}                  

void reset()
{
    ::reset();
    delete("mark/����");
}


int do_pull(string arg)
{
         object yinbin, monk;
         if (arg!="С��" && arg != "cabinet") return notify_fail("��Ҫ����ʲô��\n");
         if (monk=present("drink monk",this_object()))
         	return notify_fail(monk->name()+"˵�������ʲô��\n");
         if(query("mark/����")) 
         	return notify_fail("������С������ʲôҲû�С�\n");         
         message_vision("$N��С���\n",this_player());
         message_vision(HIR "$N������ǰһ���������Ѷ���һ������޳�����̬��ȣ�����������Ĺ������ˡ�\n"NOR,this_player());
         this_object()->set("mark/����",1);        
         this_player()->set_temp("mark/����",1);
         yinbin=new(AREA_TIEFLAG"npc/yinbin");
         yinbin->move(environment(this_player()));
         return 1;
}

int valid_leave(object me, string dir)
{
        if( userp(me) && dir == "down")
        	message_vision("$N�ֽŲ��ã������ص���\n",me);

        return 1;
}
