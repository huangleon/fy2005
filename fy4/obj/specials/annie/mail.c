// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(WHT"��"NOR, ({"letter","mail" }));
    set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("unit", "��");
			set("long", "һ��Ӳ����ŵķ�����վ��ʧ���š�\n");
            set("value", 0);
			set("no_reset",1);
			set("no_stack",1);
			set("desc_ext","�������");
        }
	::init_item();
}

void invoke(string name)
{
	set("name",WHT"�͸�"+name+"����"NOR);
	set("marks",name);
	call_out("dest",900);
}


void dest()
{
	object me;
	me = environment();
	if (me)
		tell_object(me,"һ������"+query("name")+"ƮƮҡҡ���������졣\n");
	destruct(this_object());
}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/




