#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "��÷԰");

	set("long", @LONG
������ǰ�÷԰�ˣ�ƽ�����߾���ϲ�����������ߣ�˵�������ŵ�÷�����ܾ�
������Щ���飬ÿ���ʱ������·����ƲƲ�죬��м����һ���˵����ϴ���������
����ı��·���������װ������������Ե������棬��Ψһ�����������͵Ķ�����
�ǿ�������������ȥ���������ӵģ���������ʲô÷������Ȼ÷�����ǻ���������
�����Կ��ǿ��ǡ������÷����ûʲô��������ֵ���������Ʈɢ��һ�����㡣
LONG);

	set("type","forest");
	set("outdoors", "fugui");
	set("exits",([
		"east":__DIR__"woshi1",
		"west":__DIR__"woshi",
		"north":__DIR__"chaifang",
	]) );
	set("item_desc", ([
        "÷��": "÷����û�л��������϶���һ��С���ӣ���������ܾ�Զ�ˡ�\n",
        "tree": "÷����û�л��������϶���һ��С���ӣ���������ܾ�Զ�ˡ�\n",
        "����": "������д��-[..����....����]�����������Զ���м����ֿ������ˡ�\n",
        "paizi": "������д��-[..����....����]�����������Զ���м����ֿ������ˡ�\n"
        ]) );
	set("coor/x",10);
	set("coor/y",240);
	set("coor/z",80);
	setup();
}

int dig_notify(object obj, int i)
{
	object me,jt;
	int kee;
	int max_kee;
	me = this_player();
	
	if (me->is_busy()){
		tell_object(me,"��������æ��\n");
		return 1;
	}
		
	message_vision(YEL"$N���е�"+obj->name()+"������Ӳ�ĵ��棬������������һ����\n"NOR , me);
	// Enough warning here!
	tell_object(me,YEL"�㱻����������������۷�������ͷ��������ЪЪ�ˣ�\n"NOR); 
	me->receive_damage("kee",(int)me->query("max_kee")/4);
	me->set_temp("last_damage_from","�ڸ���ɽׯ�ɻ������ˡ�\n");
	
	if (query("digged")) 
	{
		message_vision("$N����������˰���ʲôҲû�ڵ���\n", me);
    	return 1;
    }
    else
    {
   		switch ( random(3) )
   		{
   	  	case 0: 
   	       	message_vision("$N���ֵ����ƺ��и���̳�ӡ�\n",this_player());
   	       	jt = new(__DIR__"obj/bottle");
			jt->move(this_player());
			set("digged",1);
			message_vision("$N�������ӵ�"+obj->name()+"����æ����"+jt->name()+"�� \n",this_player());
   			destruct(obj);
     		break;
   	  	case 1:
        	message_vision("���ϵ�����$N����һ��,ûʲô���֡�\n",obj);
    	  	break;
   		case 2:
    	  	message_vision("�ϣ�����һ����$N���е�"+obj->name()+"���ˡ�\n",this_player());
   	  		destruct(obj);
     		break;
     	}
 	}
 	me->start_busy(3);
	return 1; 
}


void reset(){
	::reset();
		
	if (!random(5)) set("digged",0);
}

		