inherit __DIR__"tutor";

void create()
{
        set_name("�������ͼ", ({ "picture","�������ͼ", "�ڻ�"}));    
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long",
                        "��Įɳ��ѩ����ɽ���ƹ���һ��������ʿ����������޼�ʻ��\n�ӳ�����޹��ճ�һ�������Ļ��ߡ�\n");
 		set("no_shown", 1);
 		set("no_get",1);
 		set("teaching", "whip");
 		set("teaching_limit", 400);
 	}
 	
 }
