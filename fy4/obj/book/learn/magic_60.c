inherit	TUTOR;

void create()
{
	set_name("����ˮ��", ({ "magicbook" }));    
	set_weight(600);
	if( clonep() )
			set_default_object(__FILE__);
	else
	{
		set("unit", "��");
		set("long",	"һ���ֳ��ı���ֽ�飬�ּ����Ҳ�����������ȥ��
���������ص�ȴ�Ǽ�����书��learn xxx from magicbook with Ǳ�ܵ�����\n");
		set("no_transfer", 1);
		set("teaching", "magic");
		set("teaching_limit", 60);
		set("teaching_require", 40);
		set("value",500);
		set("material", "paper");
 	}
}