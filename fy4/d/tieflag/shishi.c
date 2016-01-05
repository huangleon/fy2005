#include <room.h>  
#include <ansi.h>
inherit ROOM;
void create()
{
  set("short","ʯ��");
  set("long",@LONG
ʯ�������˽ǣ����а��ţ������������أ������졢�ȡ��ơ��̡��ࡢ�����ϡ�
�ڰ�ɫ����ɫ������ǰ���м���ʯ��񼸣�����Щ�ʹ����ȣ�������ƣ��䱭��յ��
������Ŀ������ʤ�ա�
LONG
  );
  	set("exits",([
              ]));
          set("objects", ([
               BOOKS"skill/ill-quan_50" : 1, 
               __DIR__"npc/zhuzao" : 1,
       ]) );

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
 }
 void init()
{
   add_action("do_open","open"); 
   add_action("do_close","close");
}
int do_close(string arg)
{
         object ob;
         switch (arg)
         {
         case "red":
         case "����":
             if(!query("exits/red")) return notify_fail("���Ѿ��ǹص���");
             message_vision("$N�����Ź���\n",this_player());
             delete("exits/red");
             return 1;
         case "orange":
         case "����":
             if(!query("exits/orange")) return notify_fail("���Ѿ��ǹص���");
             message_vision("$N�����Ź���\n",this_player());
             delete("exits/orange");
             return 1;
         case "yellow":
         case "����":
             if(!query("exits/yellow")) return notify_fail("���Ѿ��ǹص���");
             message_vision("$N�����Ź���\n",this_player());
             delete("exits/yellow");
             return 1;  
         case "green":
         case "����":
             if(!query("exits/green")) return notify_fail("���Ѿ��ǹص���");
             message_vision("$N�����Ź���\n",this_player());
             delete("exits/green");
             return 1;
         case "cyan":
         case "����":
             if(!query("exits/cyan")) return notify_fail("���Ѿ��ǹص���");
             message_vision("$N�����Ź���\n",this_player());
             delete("exits/cyan");
             return 1;
         case "blue":
         case "����":
             if(!query("exits/blue")) return notify_fail("���Ѿ��ǹص���");
             message_vision("$N�����Ź���\n",this_player());
             delete("exits/blue");
             return 1;
         case "mag":
         case "����":
             if(!query("exits/mag")) return notify_fail("���Ѿ��ǹص���");
             message_vision("$N�����Ź���\n",this_player());
             delete("exits/mag");
             return 1;
         case "black":
         case "����":
             if(!query("exits/black")) return notify_fail("���Ѿ��ǹص���");
             message_vision("$N�����Ź���\n",this_player());
             delete("exits/blk");
             return 1;

         default: return notify_fail("��Ҫ��ʲô��\n"); 
         }
         

}
int do_open(string arg)
{
         object ob;
         switch (arg)
         {
         case "red":
         case "����":
             if(query("exits/red")) return notify_fail("���Ѿ��ǿ�����\n");
             message_vision("$N�����Ŵ�\n",this_player());
             set("exits/red",__DIR__"redroom");
             return 1;
         case "orange":
         case "����":
             if(query("exits/orange")) return notify_fail("���Ѿ��ǿ�����\n");
             message_vision("$N�����Ŵ�\n",this_player());
             set("exits/orange",__DIR__"orgroom");
             return 1;
         case "yellow":
         case "����":
             if(query("exits/yellow")) return notify_fail("���Ѿ��ǿ�����\n");
             message_vision("$N�����Ŵ�\n",this_player());
             set("exits/yellow",__DIR__"yelroom");
             return 1;  
         case "green":
         case "����":
             if(query("exits/green")) return notify_fail("���Ѿ��ǿ�����\n");
             message_vision("$N�����Ŵ�\n",this_player());
             set("exits/green",__DIR__"grnroom");
             return 1;
         case "cyan":
         case "����":
             if(query("exits/cyan")) return notify_fail("���Ѿ��ǿ�����\n");
             message_vision("$N�����Ŵ�\n",this_player());
             set("exits/cyan",__DIR__"cynroom");
             return 1;
         case "blue":
         case "����":
             if(query("exits/blue")) return notify_fail("���Ѿ��ǿ�����\n");
             message_vision("$N�����Ŵ�\n",this_player());
             set("exits/blue",__DIR__"bluroom");
             return 1;
         case "mag":
         case "����":
             if(query("exits/mag")) return notify_fail("���Ѿ��ǿ�����\n");
             message_vision("$N�����Ŵ�\n",this_player());
             set("exits/mag",__DIR__"magroom");
             return 1;
         case "black":
         case "����":
             if(query("exits/black")) return notify_fail("���Ѿ��ǿ�����\n");
             message_vision("$N�����Ŵ�\n",this_player());
             set("exits/black",__DIR__"blkroom");
             return 1;
         default: return notify_fail("��Ҫ��ʲô��\n"); 
         }
         

} 
void reset()
{
	object zhuzao;
	::reset();
	if(!(zhuzao=present("zhu zao",this_object())))
		return;
	zhuzao->delete_temp("mark/pass_array");
}
	
int valid_leave(object me, string dir)
{      
    object ob;
    ob = present("zhu zao", this_object());

    if( objectp(ob) && !me->query_temp("mark/sucarray"))
	{
		return notify_fail("���������������Ů������뿪����ġ�\n");
	}
    return 1;
}           
