// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "�޶�");
        set("long", @LONG
�ղź������ã�������ȴ�����ڵ����������ǻ�Ʒ���Ĺ��ߣ��㲻�ɾ���
���ȣ�����Խ��Խ�ȣ��ƺ��л��ڼ尾���㣬���˼������ܾ�ɫû�иı䣬����
��ʱ������Ů������������������Χ���ȵ���ʯ���㲻��Խ��Խ���
LONG
        );
   set("exits", ([ 
      "north": __DIR__"migong1", 
   ]));
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",-20);
	setup();
}

void init()
{
   add_action("do_search", "search");
}

int do_search(string arg)
{
   object me;
   int llvl;

   me = this_player();
   llvl = (int)me->query_kar();
   message_vision("$N�����ڻ��ȵ�ʯ���������š�\n",me);
   if (random(100) < llvl) { 
      tell_object(me, "�������ʯ����������һ��ͻ�����˳������һ���� \n");
      message_vision("ֻ��һ���������������ͷ���ѿ���һ�����ڡ� \n", me);
      if( !query("exits/up") ) {
         set("exits/up", __DIR__"rongdong1");
         call_out("close_path", 1);
      }
   }
   else
      tell_object(me, "��ʲô��û�ҵ���\n");
   return 1;   
}

void close_path()
{
   if( !query("exits/up") ) return;
   message("vision", "��¡һ����ͷ���ϵĳ����ֱ���ס�ˡ�\n", this_object() );
   delete("exits/up");
}

