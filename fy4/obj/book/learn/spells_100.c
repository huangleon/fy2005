inherit	TUTOR;

void create()
{
	set_name("��������", ({ "spellsbook" }));    
	set_weight(600);
	if( clonep() )
			set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long",	"һ���ֳ��ı���ֽ�飬�ּ����Ҳ�����������ȥ��
���������ص�ȴ�Ǽ�����书��learn xxx from spellsbook with Ǳ�ܵ�����\n");
		set("no_transfer", 1);
		set("teaching", "spells");
		set("teaching_limit", 100);
		set("teaching_require", 40);
		set("value",1000);
		set("material", "paper");
 	}
}