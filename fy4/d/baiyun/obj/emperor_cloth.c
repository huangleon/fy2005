#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIY"�˿ʮ�������"NOR, ({ "emperor cloth","cloth" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�ǵ�����ϲ��ܴ������ۣ����������������������㣬�Ի�ɫ��ĿɴΪ�
�˿Ϊ�棬�м�Ĳ��Ծɴ����֯����ƴ���ƣ�ͨ����ƶ��ɡ�\n");
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("value", 100);
		set("thief_obj", 1000);
	}
	::init_cloth();
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
