inherit __DIR__"tutor";

void create()
{
	set_name("��ɽ�ɺ�", ({ "chanting book","chanting" }));    
	set_weight(600);
	if( clonep() )
			set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long",	"һ���ֳ��ı���ֽ�飬�ּ����Ҳ�����\n������ȥ�����������ص�ȴ�Ǽ�����书��\n");
		set("no_drop", 1);
		set("no_get", 1);
		set("no_sell", 1);
		set("teaching", "chanting");
		set("teaching_limit", 150);
		set("value",10000);
		set("material", "paper");
 	}
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

