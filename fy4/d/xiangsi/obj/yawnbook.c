#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("����Ż�", ({ "picture","mysterious picture" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ������ĹŻ����������ϸϸ���ܵ���ӬͷС��д��Щ���֣�study����\n");
                set("value", 2);
                set("material", "paper");
       			set("cat","��ɽ�� ���ŵ��ӵĳ�������Ƿ�ġ��������è(Mimicat)");
       }
    	::init_item();
}

void init()
{
	if(this_player()==environment())
		add_action("do_study","study");
}

int do_study(string arg)
{
    object me,ob;
	int sena;
	string book, cat;
        
    me = this_player();
    if(!arg || sscanf(arg, "%s %d", book, sena)!=2 )
        return notify_fail("ָ���ʽ��study <��> <������>\n");
    if(this_object() != present(book, me)) 
          return 0;
	message("vision",me->name()+"����ר�ĵ��ж�"+name()+"��\n"NOR,environment(me),me);
	
	cat = query("cat");
	tell_object(this_player(),name()+"�ϻ���һֻ���ֵĴ���è������ע��������������һ��\n��������"+ cat+"\n");
	
	if (query("p_id")== me->query("id")) {
		tell_object(me,HIC"��ġ�͵��֮�����Ѿ��Ƿ��켫�����˿ɱ��ˣ�\n"NOR);
		return 1;
	}
	
	if (me->query_temp("annie/yawnbook_2")>50){
		tell_object(me,CYN"���ֵĴ���è��������˸����Ƿ˵����λ����λ��\n"NOR);
		set("cat",me->query("name")+"��"+me->query("id")+"��");
		set("p_id",me->query("id"));
		return 1;
	}
	
	me->add_temp("annie/yawnbook",1+sena/10);
	if (me->query_temp("annie/yawnbook") > 
			me->query_temp("annie/yawnbook_2") * me->query_temp("annie/yawnbook_2"))
	{
		me->add_temp("annie/yawnbook_2",1);
		me->set_temp("annie/yawnbook",0);
		tell_object(me,HIC"��ġ�͵��֮���������ˣ�\n"NOR);
	}
	tell_object(this_player(),"���ж��й�͵��֮���ļ��ɣ��ƺ��е��ĵá�\n");
	return 1;
}

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
