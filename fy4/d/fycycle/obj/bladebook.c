inherit __DIR__"tutor";

void create()
{
        set_name("����ʯ��", ({ "jade blade","����ʯ��", "blade" }));    
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long",
                        "һ������İ���ʯ��������Ļ��ߣ�����һ����ɵ����Ϻ���и�����ơ�\n");
 		set("no_shown", 1);
		set("no_get",1);
 		set("teaching", "blade");
 		set("teaching_limit", 400);
 	}
 	
 }
