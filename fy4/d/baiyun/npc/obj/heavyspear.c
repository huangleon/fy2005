#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
    set_name("��ͷ��ǹ", ({ "iron spear","spear" }) );
    set_weight(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "�����������У����ǵؽ��һ����ʦ�ػ�����������ǹ���������ã������Ƿ���\n");
        set("value", 100);
		set("material", "steel");
	}
    ::init_spear(20);
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
