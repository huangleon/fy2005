#include <room.h>  
inherit ROOM;
void create()
{
  set("short","������");
  set("long",@LONG
������ȥ���������б̲����ԣ�������ɽ��������һƬɽ��ˮɫ��������һ����
�ŷ�����һƬ��ˮ��㲻��ʮ���ɣ��������ɽ��ˮ�����ǻ��ڱ��ϵĵ���ͼ����
ֻ�ǻ���ίʵ̫�����棬Զ���������������磬��ɫ�����������Σ�ʹɽɫ������
�縲�Դ䣬�Ͱ���Ʈ����Ǽ�ֻ���Գ�঵���죬Ҳ������Ҫ�Ʊڷɳ������Ƴ���
�����̲�֮�ϣ�Ҳ�м�ֻ�׶측����䣬����һ��С������ķ���Ʈ��ˮ�ϣ�ֻ��
���������ɴ�ʹ�����ˮ�棬˭Ҳ�Ʋ������������ֻ�Ƽ�һ�����̴���һ������
֮��Ʈ���Դ�������ɢ������
LONG
  );
  	set("exits/south" ,__DIR__"blkroom");
    set("objects",([
    	__DIR__"npc/zhuo" : 1,
    	__DIR__"npc/feng" : 1,
    ]) );

	set("coor/x",10);
	set("coor/y",20);
	set("coor/z",0);
	setup();
 }
 
 
void reset()
{   
	object *inv;
	int i,no_reset;
	inv=all_inventory(this_object());
	for (i=0;i<sizeof(inv);i++)
	{
	    if(base_name(inv[i])==__DIR__"npc/lishi")
		{
			if (!inv[i]->is_fighting())                  
		    	destruct(inv[i]);
		    else
		    	no_reset=1;
		}
		else
		if(base_name(inv[i])==__DIR__"npc/feng2" )
		{
			if (!inv[i]->is_fighting())
				destruct(inv[i]);
			else  
				no_reset=1;
		}
	}
	if(!no_reset) ::reset();
}

void init()
{
	add_action("do_swim","swim");
}

int arrive(object me, object room)
{
        if(me && environment(me) == this_object())
        {
        me->move(room);
        message_vision("$N�ӳ�ˮ������������\n",me);
        }
        return 1;
}

int do_swim(string arg)
{
	object me;
	object room;
	me=this_player();
	if(arg == "��ˮ" || arg == "pond" || !arg) {
		if(me->is_fighting()) return 0;
		if(random(2)) return notify_fail("��ˮ̫��β���ȥ��\n");
		message_vision("$N��ͨһ�������ˮ��һ���٣�������ȥ��\n",me);
		me->start_busy(7);
		if(!objectp(room=find_object(__DIR__"ark")))
			room=load_object(__DIR__"ark");
		call_out("arrive",7,me,room);
		return 1;
	}
	return 0;
}
