// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
��վ��һ��ɽ���ϣ������������˸�ʽ���������ܵ��ͱڣ���Щ���ܻ�������
�޵Ļ��䣬������һ���޴�Ĺ�̺���ͱ������˺��档��Զ������ֻ��Ⱥɽ����
�������ƣ�ɽ�嶼��û��һƬ��ãã����֮�С�
LONG
        );
   set("exits", ([ 
      "north" : __DIR__"gudi",
   ]));
   
   set("item_desc", ([
      "����" : "�����Ͽ�����ɫ�Ļ��䣬͸��ï�ܵ����ܣ�����Լ���Կ���һ���ʯ��\n",
      "vine" : "�����Ͽ�����ɫ�Ļ��䣬͸��ï�ܵ����ܣ�����Լ���Կ���һ���ʯ��\n",
      "�ͱ�" : "�ͱںܸ߲��Һܶ��������ǲ�����������ȥ�ġ�\n",
      "cliff" : "�ͱںܸ߲��Һܶ��������ǲ�����������ȥ�ġ�\n",
   ]) );

   	set("outdoors", "laowu");
	set("coor/x",150);
	set("coor/y",160);
	set("coor/z",10);
	setup();
}

void init()
{
   	add_action("do_push", "push");
}

int do_push(string arg)
{
   	object me, obj;
   	int flvl;

   	me = this_player();
   	flvl = (int)me->query_str();
   	if(!arg || (arg != "stone" && arg != "ʯͷ" && arg != "rock"))
      	return 0;
   	if (flvl >= 20) {  
    	if (!query("exits/enter")) {
         	message_vision("$N������˫��, ʹ����������������ܺ�Ĵ�ʯ��ȥ�� \n", me);
         	message_vision("��ʯ�������Ա߻�ȥ, ¶����һ�����ڡ� \n", me);
         	set("exits/enter", __DIR__"midao8");
         	call_out("close_path", 2);      
         	return 1;
      	}
   	}
   	else {
      if (!query("exits/enter")) {
      	message_vision("$N������˫��, ʹ����������������ܺ�Ĵ�ʯ��ȥ��ʯͷ΢΢�ζ��˼��£� \n", me);
         return 1;
      }
   }
   return 0;
}


void close_path()
{
   if(!query("exits/enter") ) return;
   message("vision", "ֻ����֨֨��ʯͷ�ֻ��˻��������˶��ڡ�\n", this_object() );
   delete("exits/enter");
}
