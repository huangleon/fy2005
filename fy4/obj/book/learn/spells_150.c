inherit	TUTOR;

void create()
{
	set_name("���۵���", ({ "spellsbook" }));    
	set_weight(600);
	if( clonep() )
			set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long",	"һ���ֳ��ı���ֽ�飬�ּ����Ҳ�����������ȥ��
���������ص�ȴ�Ǽ�����书��learn xxx from spellsbook with Ǳ�ܵ�����\n");
		set("no_drop", 1);
		set("teaching", "spells");
		set("teaching_limit", 150);
		set("teaching_require", 100);
		set("value",10000);
		set("material", "paper");
 	}
}