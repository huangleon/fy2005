#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIW"���ƶ�"NOR);
    set("long", @LONG
�������ģ�����һ�ߡ�������ǰ��Ƶ��ˣ�����������ã�����ɳ̲�����ϸ��
��ˮտ����̣����δ������������İ�ĭ�����ź���������������ƣ��������۴��̡�
һ�������ɾ�һ�㡣���Ű����Ǹ������[37m��ͷ[32m��ͣ�����������Ƶ��Ĵ�ֻ�������ĺ�
��������䣬ԭ������������ֻҪ������ͷ�Ĵ��Ҽ��ɹʹ��뵺��
LONG
    );    
    set("exits",       
      ([        
	"south" : __DIR__"huangsha1",
      ]));
    set("objects",
      ([ 
	//	     __DIR__"obj/sand" : 1,
      ])); 
    set("outdoors", "baiyun");
    set("coor/x",0);
    set("coor/y", 0);
    set("coor/z",0);
    set("item_desc", ([
	"��ͷ": "���Ƶ�����ͷ����Ҳ����ķ�æ���������׷����ϲ�������Ҷ���׵�ľ������\n
������ˣ������к���yell���ϲ���һ����\n",
               "matou": "���Ƶ�����ͷ����Ҳ����ķ�æ���������׷����ϲ�������Ҷ���׵�ľ������\n
������ˣ������к���yell���ϲ���һ����\n",
               "dock": "���Ƶ�����ͷ����Ҳ����ķ�æ���������׷����ϲ�������Ҷ���׵�ľ������\n
������ˣ������к���yell���ϲ���һ����\n",
        ]) );

	setup();
}

void init()
{               
        add_action("do_yell","yell");
}

void boat_come(object who)
{
	object byboat;
	object oldman;
	object *inv;
	int i;

	if (environment(who)!= this_object())	return;
		
	if (!objectp(byboat=find_object(__DIR__"boat2")))
		byboat=load_object(__DIR__"boat2");
	 message_vision(CYN"�����ϲ�Ц���е�Ӧ��һ����������㣬ľ��С�۱��ѿ�����ͷ���ϡ�\n"NOR,who);
	message_vision(WHT"�����ϲ����Ϻ�����Ц�Ǻǵ������͹٣��ϴ��ɣ���\n"NOR,who);
	set("exits/down",__DIR__"boat2");
	call_out("boat_leave",3,byboat);
}


void boat_leave(object byboat)
{
	if (query("exits/down")) 
	delete("exits/down");
	if (byboat->query("exits/up")) 
                byboat->delete("exits/up");
	message("vision","�����ϲ��ɿ�����������ˮ��С�ۻ������밶�ߣ�����\n",this_object()); 
    byboat->set_temp("mark/dest","island");
	message("vision","�����ϲ��ɿ�����������ˮ��С�ۻ������밶�ߣ�����\n",byboat);
}



int do_yell()
{
	object me;
	object room;
	me = this_player();
	message_vision(CYN"$N�򴬼��ϲ������к����������ң����Ϻ�����\n"NOR , me );
	call_out("boat_come",1,me);
	return 1;
}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
