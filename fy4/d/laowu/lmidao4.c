// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ɽ���ص�");
        set("long", @LONG
���������ص��ľ�ͷ��������·û���κγ��ڣ���ǰ����ʯ�����и����ڣ���
�ڲ���ֻ�ݵ�һ�˽�������ȴ��һ���ʯ�����浲ס������֮���㿴�����κ���
���ܳ�ȥ�ĵط���
LONG
        );
        set("exits", ([ 
		  "southwest" : __DIR__"lmidao2",
	]));
   	set("item_desc", ([
      		"stone" : "һ���ʯ��ס��һ��һ�˴�С�Ķ��ڡ� \n",
      		"rock" : "һ���ʯ��ס��һ��һ�˴�С�Ķ��ڡ� \n",
		"ʯͷ" : "һ���ʯ��ס��һ��һ�˴�С�Ķ��ڡ� \n",
   	]) );
	set("coor/x",110);
	set("coor/y",40);
	set("coor/z",0);
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
      	if (!query("exits/out")) {
	         message_vision("$N������˫��, ʹ��������������ʯ��ȥ�� \n", me);
	         message_vision("��ʯ�������Ա߻�ȥ, ¶����һ�����ڡ� \n", me);
	         set("exits/out", __DIR__"dongkou");
	         call_out("close_path", 2);      
	         return 1;
      	}
   	}
   	else {
      		if (!query("exits/out")) {
      			message_vision("$N������˫��, ʹ��������������ʯ��ȥ��ʯͷ��˿������ \n", me);
         		return 1;
      		}
   	}
   	return 0;
}


void close_path()
{
   	if(!query("exits/out") ) return;
   	message("vision", "ֻ����֨֨��ʯͷ�ֻ��˻��������˶��ڡ�\n", this_object() );
   	delete("exits/out");
}


